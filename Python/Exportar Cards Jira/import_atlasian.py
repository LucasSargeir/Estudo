import requests
import pprint as pp

cookies = {
	'ajs_anonymous_id': '',
	'cloud.session.token': '',
	'atlassian.xsrf.token': '',
	'JSESSIONID': ''
}

urlBacklog = ""
baseUrlIssue = ""

response = requests.get(urlBacklog, cookies=cookies).json()

issues  = {}
sprints = {}

for index, issue in enumerate(response['issues']):
	
	issueResult = requests.get(baseUrlIssue.replace('#ID#', issue['key']), cookies=cookies).json()
	description = list(filter(lambda i: i['tabId'] == 'DESCRIPTION',issueResult['tabs']['defaultTabs']))[0]

	print(f'Loading issues... {(index/len(response["issues"])*100):.2f}%')

	filtered_issue = {
		'issue_id':  issue['id'],
		'issue_key': issue['key'],
		'type': issue['typeName'],
		'title': issue['summary'],
		'priority': issue['priorityName'] if 'priorityName' in issue.keys() else None,
		'assigneeName': issue['assigneeName'] if 'assigneeName' in issue.keys() else None,
		'epic': issue['epicField'] if 'epicField' in issue.keys() else None,
		'estimate': issue['estimateStatistic'],
		'status': issue['status'],
		'description': description['sections']
	}

	issues[issue['id']] = filtered_issue

print(f'Loading issues... 100.00%   COMPLETED\n')

for index, sprint in enumerate(response['sprints']):
	
	print(f'Creating Sprints... {(index/len(response["sprints"])*100):.2f}%')

	filteres_sprint = {
		'sprint_id': sprint['id'],
		'sprint_key': sprint['name'],
		'state': sprint['state'],
		'goal': sprint['goal'],
		'start_date': sprint['isoStartDate'],
		'end_date': sprint['isoEndDate'],
		'issues': list(map(lambda i: issues[i], sprint['issuesIds'])),
	}
	sprints[sprint['id']] = filteres_sprint

print(f'Creating Sprints... 100.00%   COMPLETED\n')
print('Exporting to file...')

f = open('cards_jira.json', 'w', encoding="utf-8")
f.write(str(list(sprints.values())))
f.close()

pp.pprint(sprints)