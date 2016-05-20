#ifndef PHP_SAMPLE3_H
#define PHP_SAMPLE3_H

#define PHP_SAMPLE3_EXTNAME "sample3"
#define PHP_SAMPLE3_EXTVER	"1.0"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

extern zend_module_entry sample3_module_entry;
#define phpext_sample3_ptr &sample3_module_entry

#endif /* PHP_SAMPLE3_H */
