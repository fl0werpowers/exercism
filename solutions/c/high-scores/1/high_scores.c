#include "high_scores.h"

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
  if (scores_len == 0)
    return 0;
  size_t idx = 0;
  size_t scores_written = 0;
  while (idx < scores_len) {
    if (scores[idx] > output[2]) {
      if (scores[idx] > output[1]) {
        if (scores[idx] > output[0]) {
          output[0] = scores[idx];
        } else {
          output[1] = scores[idx];
        }
      } else {
        output[2] = scores[idx];
      }
    }
    idx++;
  }
  idx = 0;
  while (idx < 3) {
    if (output[idx] > 0)
      scores_written++;
    idx++;
  }
  return scores_written;
}
