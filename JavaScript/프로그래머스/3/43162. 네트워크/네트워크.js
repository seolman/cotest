function dfs(n, computers, idx, visited) {
  visited[idx] = true;
  for (let i = 0; i < n; i++) {
    if (computers[idx][i] === 1 && !visited[i]) {
      dfs(n, computers, i, visited);
    }
  }
}

function solution(n, computers) {
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