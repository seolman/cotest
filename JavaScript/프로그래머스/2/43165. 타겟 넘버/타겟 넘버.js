function dfs(numbers, target, idx, sum) {
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

function solution(numbers, target) {
  const answer = dfs(numbers, target, 0, 0);
  return answer;
}
