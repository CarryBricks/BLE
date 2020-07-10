#include "app_timer.h"
#include "nrf_log.h"
#include "soft_timer.h"
#include "user_type.h"






//下面为定时器的设计使用
APP_TIMER_DEF(m_timer_id);  
u8 TIME=0;
#define TIME_LEVEL_MEAS_INTERVAL          APP_TIMER_TICKS(1000)

APP_TIMER_DEF(m_timer_id_1);  
#define TIME_LEVEL_MEAS_INTERVAL_1          APP_TIMER_TICKS(2000)


static void TIME_update(void) //上传数据给手机，本例程是定时器自增一 ，2秒更新一次
{
    u8  TIME_level;

    TIME_level=TIME;
	  TIME++;
	  //NRF_LOG_INFO("%d",(u8)TIME_level);

}

static void TIME_timeout_handler(void * p_context)
{
    UNUSED_PARAMETER(p_context);
    TIME_update();
}


static void TIME_timeout_handler_1(void * p_context)
{
    UNUSED_PARAMETER(p_context);
    //NRF_LOG_INFO("TIME_timeout_handler1");
}
/**@brief Function for the Timer initialization.
 *
 * @details Initializes the timer module. This creates and starts application timers.
 */
void soft_timers_init(void)
{
    // Initialize timer module.
    ret_code_t err_code = app_timer_init();
    APP_ERROR_CHECK(err_code);

    // Create timers.

    /* YOUR_JOB: Create any timers to be used by the application.
                 Below is an example of how to create a timer.
                 For every new timer needed, increase the value of the macro APP_TIMER_MAX_TIMERS by
                 one.
       ret_code_t err_code;
       err_code = app_timer_create(&m_app_timer_id, APP_TIMER_MODE_REPEATED, timer_timeout_handler);
       APP_ERROR_CHECK(err_code); */
		//创建一个定时，设置定时器模式
	 err_code = app_timer_create(&m_timer_id,
                                APP_TIMER_MODE_REPEATED,
                                TIME_timeout_handler);
    APP_ERROR_CHECK(err_code);
	
	
	
	  err_code = app_timer_create(&m_timer_id_1,
                                APP_TIMER_MODE_REPEATED,
                                TIME_timeout_handler_1);
    APP_ERROR_CHECK(err_code);
		
		
		
    // Start application timers.定时时间间隔
    err_code = app_timer_start(m_timer_id, TIME_LEVEL_MEAS_INTERVAL, NULL);
    APP_ERROR_CHECK(err_code);
	
	  err_code = app_timer_start(m_timer_id_1, TIME_LEVEL_MEAS_INTERVAL_1, NULL);
    APP_ERROR_CHECK(err_code);
}


