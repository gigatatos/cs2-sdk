#ifndef CS2_PROJECT_USER_CMD_HPP
#define CS2_PROJECT_USER_CMD_HPP

namespace sdk
{
    class c_cmd_qangle {
    public:
        PAD( 24 );   //0x0000
        float x;     //0x0018
        float y;     //0x001C
        float z;     //0x0020
        PAD( 1052 ); //0x0024
    }; //Size: 0x0440

    class c_user_cmd_base {
    public:
        PAD( 64 );                  //0x0000
        c_cmd_qangle *m_viewangles; //0x0040
        PAD( 1016 );                //0x0048
    }; //Size: 0x0440

    class c_user_cmd {
    public:
        PAD( 48 );               //0x0000
        c_user_cmd_base *m_base; //0x0030
        PAD( 24 );               //0x0038
        uint32_t m_buttons;      //0x0050
        PAD( 1004 );             //0x0054

        c_user_cmd_base* get_base( )
        {
            return m_base;
        }
    }; //Size: 0x0440
}// namespace sdk

#endif//CS2_PROJECT_USER_CMD_HPP
