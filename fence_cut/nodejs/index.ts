/**
 * https://www.algospot.com/judge/problem/read/FENCE
 * 결과: ms
 */

import * as readline from 'readline';
import * as process from 'process';

let rl: readline.Interface = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input: string[] = [];

class game_manager{
  temp: Buffer;
  buffer: Buffer;

  constructor()
  {
    this.buffer = Buffer.from([]);
    this.temp = Buffer.from([]);
  }

  input_data(data: string): void
  {
    this.buffer = Buffer.from(data);
    this.temp = Buffer.from(data);
  }

  find_max_size_fence(): number
  {
    
  }

  find_answer(): void
  {
    
  }

  output_data()
  {
    console.log(this.buffer.toString());
  }
}

function main(): void
{
  let numTests: number = 0;
  numTests = Number(input[0]);

  let gm: game_manager = new game_manager();

  for(let i = 1; i <= numTests; i++){
    gm.input_data(input[i]);
    gm.find_answer();
    gm.output_data();
  }
}

rl.on('line', (line)=>{
  input.push(line.trim());
});

rl.on('close', ()=>{
  main();
});