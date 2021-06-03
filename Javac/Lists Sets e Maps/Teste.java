import java.util.*;

@SuppressWarnings("unchecked")

public class Teste{

	public static void main(String args[]){

		Iterator i;

		ArrayList a = new ArrayList();
		HashSet h = new HashSet();
		HashMap m = new HashMap();


		System.out.println("ArrayList____________________");

		a.add("Joao");
		a.add("Maria");
		a.add("Pedro");
		a.add("Lucas");
		a.add("Enzo");

		i = a.iterator();

		while(i.hasNext()){

			String nome = (String)i.next();
			System.out.println(nome);
			
		}

		/*for(int j = 0; j < a.size(); j++){

			System.out.println(a.get(i));

		}*/








		System.out.println("\n\nHashSet____________________");

		h.add("Joao");
		h.add("Maria");
		h.add("Pedro");
		h.add("Lucas");
		h.add("Enzo");


		i = h.iterator();

		while(i.hasNext()){

			String nome = (String)i.next();
			System.out.println(nome);
			
		}









		System.out.println("\n\nHashMap____________________");

		m.put("Joao", 12);
		m.put("Maria", 13);
		m.put("Pedro", 14);
		m.put("Lucas", 15);
		m.put("Enzo", 16);


		i = m.keySet().iterator();

		while(i.hasNext()){

			String nome = (String)i.next();
			System.out.println(m.get(nome));
			
		}

	}

}