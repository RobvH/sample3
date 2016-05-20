#include "php_sample3.h"

static function_entry php_sample3_functions[] = {
	{ NULL, NULL, NULL }
};

PHP_MINIT_FUNCTION(sample3)
{
	return SUCCESS;
}

zend_module_entry sample3_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE3_EXTNAME,
	php_sample3_functions,
	PHP_MINIT(sample3),
	NULL, 					/* MSHUTDOWN */
	NULL,					/* RINIT */
	NULL,					/* RSHUTDOWN */
	NULL, 					/* MINFO */
	PHP_SAMPLE3_EXTVER,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE3
ZEND_GET_MODULE(sample3)
#endif
