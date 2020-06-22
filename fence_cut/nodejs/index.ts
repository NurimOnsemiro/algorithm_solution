/**
 * https://www.algospot.com/judge/problem/read/FENCE
 * 결과: 208ms
 */

import * as readline from 'readline';
import * as process from 'process';

let rl: readline.Interface = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input: string[] = [];

class stack_base {
  data: number[];
  private top: number;

  constructor()
  {
    this.data = [];
    this.data.length = 20001;
    this.top = 0;
    this.data[this.top] = 0;
  }

  push(value: number)
  {
    if(this.top === this.data.length - 1){
      return;
    }
    this.top++;
    this.data[this.top] = value;
  }

  front(): number
  {
    if(this.top === 0){
      throw new Error("stack is empty");
    }
    return this.data[this.top];
  }

  pop()
  {
    if(this.top === 0){
      throw new Error("stack is empty");
    }
    this.top--;
  }

  empty(): boolean
  {
    if(this.top === 0) return true;
    else return false;
  }
}

class game_manager{
  fenceArr: number[];
  numFences: number;
  maxSquareSize: number;

  constructor()
  {
    this.numFences = 0;
    this.maxSquareSize = 0;
    this.fenceArr = [];
  }

  clear_data()
  {
    this.fenceArr = [];
    this.fenceArr.length = 20001;
    this.numFences = 0;
    this.maxSquareSize = 0;
  }

  input_data(fenceStrArr: string[])
  {
    for(let i=0;i<fenceStrArr.length;i++){
      this.fenceArr[i] = Number(fenceStrArr[i]);
    }
    this.fenceArr[fenceStrArr.length] = 0;
    this.numFences = fenceStrArr.length;
  }

  find_answer()
  {
    let stk: stack_base = new stack_base();
    this.fenceArr[this.numFences] = 0;

    for(let i=0;i<=this.numFences;i++){
      while(!stk.empty() && this.fenceArr[stk.front()] >= this.fenceArr[i] ){
        let pos: number = stk.front()
        stk.pop();

        let width: number = stk.empty() ? i : (i - stk.front() - 1);
        let squareSize: number = width * this.fenceArr[pos];
        if(squareSize > this.maxSquareSize){
          this.maxSquareSize = squareSize;
        }
      }
      stk.push(i);
    }
  }

  output_data()
  {
    console.log(this.maxSquareSize);
  }
}

function main(): void
{
  let numTests: number = 0;
  let idx: number = 0;
  numTests = Number(input[idx++]);

  let gm: game_manager = new game_manager();
  

  while(numTests){
    let numFences: number = Number(input[idx++]);

    let fecneDataStr: string = input[idx++];
    let fenceArr: string[] = fecneDataStr.split(' ');

    gm.clear_data();
    gm.input_data(fenceArr);
    gm.find_answer();
    gm.output_data();

    numTests--;
  }
}

rl.on('line', (line)=>{
  input.push(line.trim());
});

rl.on('close', ()=>{
  main();
});