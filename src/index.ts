function dfs(numbers: number[], target: number, idx: number, sum: number): number {
  if (numbers.length === idx) {
    if (target === sum) {
      return 1;
    } else {
      return 0;
    }
  }

  const add_path = dfs(numbers, target, idx + 1, sum + numbers[idx]);
  const sub_path = dfs(numbers, target, idx + 1, sum - numbers[idx]);
  return add_path + sub_path;
}

function solution(numbers: number[], target: number) {
  const answer = dfs(numbers, target, 0, 0);
  return answer;
}

const numbers = [1, 1, 1, 1, 1];
const target = 3;
const expected = 5;
const result = solution(numbers, target);
