function dfs(n: number, computers: number[][], idx: number, visited: boolean[]) {
  visited[idx] = true;
  for (let i = 0; i < n; i++) {
    if (computers[idx][i] === 1 && !visited[i]) {
      dfs(n, computers, i, visited);
    }
  }
}

function solution(n: number, computers: number[][]) {
  let answer = 0;
  const visited = Array.from({ length: n }, () => false);
  for (let i = 0; i < n; i++) {
    if (!visited[i]) {
      answer++;
      dfs(n, computers, i, visited);
    }
  }
  return answer;
}

const n = 3;
const computers = [[1, 1, 0], [1, 1, 0], [0, 0, 1]];
const expected = 2;
const result = solution(n, computers);

if (expected === result) {
  console.log("result: ", result);
} else {
  console.log("result: ", result, "expected: ", expected);
}
