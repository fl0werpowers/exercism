#include "high_scores.h"

#define MAX_TOP_THREE (3)

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
  return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
  if (scores_len == 0)
    return 0;
  int max_score = scores[scores_len - 1];
  int next_score = personal_best(scores, scores_len - 1);
  if (max_score < next_score)
    max_score = next_score;
  return max_score;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  size_t idx;
  size_t scores_idx;
  size_t scores_idx_store[3];

  scores_idx = 0;
  while (scores_idx < 3 && scores_idx < scores_len) {
    output[scores_idx] = 0;
    scores_idx_store[scores_idx] = scores_len;
    idx = 0;
    while (idx < scores_len) {
      if (output[scores_idx] <= scores[idx] && idx != scores_idx_store[0] &&
          idx != scores_idx_store[1]) {
        output[scores_idx] = scores[idx];
        scores_idx_store[scores_idx] = idx;
      }
      idx++;
    }
    scores_idx++;
  }
  return scores_idx;
}
