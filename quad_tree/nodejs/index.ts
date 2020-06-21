/**
 * https://www.algospot.com/judge/problem/read/QUADTREE
 * 결과: 120ms
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

  input_data(data: string)
  {
    this.buffer = Buffer.from(data);
    this.temp = Buffer.from(data);
  }

  find_quadtree(currIndex: number[]) : number
  {
    const head: string = this.buffer.toString()[currIndex[0]];
    currIndex[0]++;

    if(head === 'w' || head === 'b'){
      return 1;
    }

    const startPos: number = currIndex[0];

    const upperLeftLength: number = this.find_quadtree(currIndex);
    const upperRightLength: number = this.find_quadtree(currIndex);
    const lowerLeftLength: number = this.find_quadtree(currIndex);
    const lowerRightLength: number = this.find_quadtree(currIndex);

    const upperLength: number = upperLeftLength + upperRightLength;
    const lowerLength: number = lowerLeftLength + lowerRightLength;
    const upperEndPos: number = startPos + upperLength;
    const lowerStartPos: number = startPos + upperLength;
    const lowerEndPos: number = lowerStartPos + lowerLength;
    const newUpperStartPos: number = startPos + lowerLength;

    if(upperLength > lowerLength){
      this.buffer.copy(this.temp, 0, startPos, upperEndPos);
      this.buffer.copy(this.buffer, startPos, lowerStartPos, lowerEndPos);
      this.temp.copy(this.buffer, newUpperStartPos, 0, upperLength);
    }
    else{
      this.buffer.copy(this.temp, 0, lowerStartPos, lowerEndPos);
      this.buffer.copy(this.buffer, newUpperStartPos, startPos, upperEndPos);
      this.temp.copy(this.buffer, startPos, 0, lowerLength);
    }

    const totalLength: number = upperLength + lowerLength + 1;
    return totalLength;
  }

  find_answer()
  {
    let currIndex: number[] = [0];
    this.find_quadtree(currIndex);
  }

  output_data()
  {
    console.log(this.buffer.toString());
  }
}

function main()
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