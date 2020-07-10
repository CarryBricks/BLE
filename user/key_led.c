#include "stdbool.h"
#include "key_led.h"
#include "user_type.h"
#include "bsp_btn_ble.h"
#include "nrf_log.h"



static void bsp_event_handler(bsp_event_t event)
{
    //ret_code_t err_code;

    switch (event)
    {
        case BSP_EVENT_SLEEP:
//            sleep_mode_enter();
            break; // BSP_EVENT_SLEEP

        case BSP_EVENT_DISCONNECT:
//            err_code = sd_ble_gap_disconnect(m_conn_handle,
//                                             BLE_HCI_REMOTE_USER_TERMINATED_CONNECTION);
//            if (err_code != NRF_ERROR_INVALID_STATE)
//            {
//                APP_ERROR_CHECK(err_code);
//            }
            break; // BSP_EVENT_DISCONNECT

        case BSP_EVENT_WHITELIST_OFF:
//            if (m_conn_handle == BLE_CONN_HANDLE_INVALID)
//            {
//                err_code = ble_advertising_restart_without_whitelist(&m_advertising);
//                if (err_code != NRF_ERROR_INVALID_STATE)
//                {
//                    APP_ERROR_CHECK(err_code);
//                }
//            }
            break; // BSP_EVENT_KEY_0

				case BSP_EVENT_KEY_4:
						  //nrf_gpio_pin_toggle(LED_2);
				    NRF_LOG_INFO("key_4     long  pressed....\n");
				break;


				#if  1
				case BSP_EVENT_KEY_3:
						  //nrf_gpio_pin_toggle(LED_2);
				    NRF_LOG_INFO("key_4       pressed....\n");
				break;
				#endif
						 
        default:
            break;
    }
}


void buttons_leds_init(bool * p_erase_bonds)
{
    ret_code_t err_code;
    bsp_event_t startup_event;

    err_code = bsp_init(BSP_INIT_LEDS | BSP_INIT_BUTTONS, bsp_event_handler);
    APP_ERROR_CHECK(err_code);

    err_code = bsp_btn_ble_init(NULL, &startup_event);
    APP_ERROR_CHECK(err_code);

    *p_erase_bonds = (startup_event == BSP_EVENT_CLEAR_BONDING_DATA);
}


