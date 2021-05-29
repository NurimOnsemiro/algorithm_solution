function solution(name) {
    var answer = 0;
    return answer;
}

const aValue = 'A';
const zValue = 'Z';

function getMinDistFromLetter(value){
    let aDist = value.charCodeAt(0) - aValue.charCodeAt(0);
    let zDist = zValue.charCodeAt(0) - value.charCodeAt(0) + 1;
    if(aDist > zDist) return zDist;
    else return aDist;
}

function main(){
    let input = 'JARON';
    let base = '';
    for(let i=0;i<input.length;i++){
        //INFO: 글자 수만큼 A로 초기화
        base += 'A';
    }

    let distArr = new Array(input.length).fill(0);
    //console.log(Number(zValue) - Number(aValue));
    for(let i=0;i<input.length;i++){
        distArr[i] = getMinDistFromLetter(input[i]);
        console.log(distArr[i]);
    }

    let itemInfo = {
        direction: 0,
        distSum: 0,
        itemSum: 0
    };

    let queue = [];
    queue.push(1);
    queue.push(distArr.length - 1);

    while(queue.length !== 0){
        
    }
    for(let i=0;i<distArr.length;i++){

    }
}
main();