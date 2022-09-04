#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t calc_diag_stamp_diff(const char *dlog_filename,
			     const char *tlog_filename, const char **error);

#ifdef __cplusplus
}
#endif
