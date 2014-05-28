#ifndef HTWSCONFIG_ALL_H_
#define HTWSCONFIG_ALL_H_


//#define PROJECT_MKK
#define PROJECT_CONSOL


#include "../htwsconfig_local_pre.h"

#ifdef PROJECT_MKK
#include "../proj_kijelzo/project_config_pre.h"
#elif defined(PROJECT_CONSOL)
#include "../proj_consol/project_config_pre.h"
#else
#error no project defiend
#endif

#include "htwsconfig_pre_main.h"
#include "htwsconfig_pre_misc.h"

#ifdef PROJECT_MKK
#include "../proj_kijelzo/project_config.h"
#elif defined(PROJECT_CONSOL)
#include "../proj_consol/project_config.h"
#else
#error no project defiend
#endif

#include "htwsconfig_platform.h"



#include "htwsconfig_post_main.h"
#include "htwsconfig_post_misc.h"

#include "../htwsconfig_local_post.h"
#endif /* HTWSCONFIG_ALL_H_ */
