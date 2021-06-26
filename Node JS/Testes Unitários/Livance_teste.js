const _ = require('lodash');
const Mocha = require('mocha');
const assert = require('assert');
const mocha = new Mocha();

mocha.suite.emit('pre-require', this, 'solution', mocha)


function detectHighestPeak(A) {
 
  if(A.length < 3){
    return -1;
  }
  
  let peaks = [];
  let peaks_index = 0;
  
  let peak = [];
  let num_position;
  
  let nums_got = 0;
  let higher_peak_index = -1;
  let higher_peak_value = 0;
  
  for(var i = 0; i < A.length; i++){
    if(i == 0){
      num_position = i;
    }
    else{
      
      if(nums_got == 0){
        if(A[i-1] > A[i]){
          if(num_position == i - 1){
            num_position = i;
          }
          else{
            peak[nums_got++] = A[num_position];
            peak[nums_got++] = A[i - 1];
          }
        }
        else if(A[i-1] === A[i]){
          num_position = i;
          nums_got = 0;
        }
      }
      else if(nums_got === 2){
        if(A[i-1] < A[i]){
          peak[nums_got++] = A[i-1];
          peak[nums_got] = Math.min(peak[1] - peak[0], peak[1] - peak[2]);
          peaks[peaks_index] = peak.slice();
          nums_got = 0;
          num_position = i-1;
          
          if(higher_peak_index === -1){
            higher_peak_index = peaks_index;
            higher_peak_value = peaks[higher_peak_index][3];
          }
          else{
            if(higher_peak_value < peaks[peaks_index][3]){
              higher_peak_index = peaks_index;
              higher_peak_value = peaks[peaks_index][3];
            }
          }
          
          peaks_index++;
          
        }   
      }
      
    }
  }
  
  if(nums_got === 2){
    if(A[i-1] < A[i-2]){
      peak[nums_got++] = A[i-1];
      peak[nums_got] = Math.min(peak[1] - peak[0], peak[1] - peak[2]);
      peaks[peaks_index] = peak.slice();
      
       if(higher_peak_index === -1){
          higher_peak_index = peaks_index;
          higher_peak_value = peaks[higher_peak_index][3];
        }
        else{
          if(higher_peak_value < peaks[peaks_index][3]){
            higher_peak_index = peaks_index;
            higher_peak_value = peaks[peaks_index][3];
          }
        }
    }
  }
  
  if(higher_peak_index === -1){
    return -1;
  }
  else{
    return higher_peak_value;
  }
}


// Create as many tests as you want

describe('Example 1', () => {
   it('Should Return 3', () => {
     const A = [0,1,3,0,-1,1,0,-3,2,3];
     assert.equal(detectHighestPeak(A), 3);
   })
})

describe('Example 2', () => {
   it('Should Return 4', () => {
     const A = [0,3,2,0,4,3,0,-3,2,3];
     assert.equal(detectHighestPeak(A), 4);
   })
 })

describe('Example 3', () => {
   it('Should Return 5', () => {
     const A = [0,1,2,3,4,6,4,3,2,1];
     assert.equal(detectHighestPeak(A), 5);
   })
 })

describe('Example 4', () => {
   it('Should Return 3', () => {
     const A = [0,3,2,0,4,4,3,0,-3,2,3];
     assert.equal(detectHighestPeak(A), 3);
   })
 })

describe('Example 5', () => {
   it('Should Return -1', () => {
     const A = [0];
     assert.equal(detectHighestPeak(A), -1);
   })
 })

describe('Example 6', () => {
   it('Should Return -1', () => {
     const A = [0,1,2,3,4,5,5,6,7];
     assert.equal(detectHighestPeak(A), -1);
   })
 })

describe('Example 7', () => {
   it('Should Return -1', () => {
     const A = [6,5,4,1,7];
     assert.equal(detectHighestPeak(A), -1);
   })
 })

mocha.run();
