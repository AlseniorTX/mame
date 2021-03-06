// license:BSD-3-Clause
// copyright-holders:Curt Coder
/**********************************************************************

    Commodore Plus/4 standard cartridge emulation

**********************************************************************/

#include "emu.h"
#include "std.h"



//**************************************************************************
//  DEVICE DEFINITIONS
//**************************************************************************

DEFINE_DEVICE_TYPE(PLUS4_STD, plus4_standard_cartridge_device, "plus4_standard", "Plus/4 standard cartridge")



//**************************************************************************
//  LIVE DEVICE
//**************************************************************************

//-------------------------------------------------
//  plus4_standard_cartridge_device - constructor
//-------------------------------------------------

plus4_standard_cartridge_device::plus4_standard_cartridge_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock) :
	device_t(mconfig, PLUS4_STD, tag, owner, clock),
	device_plus4_expansion_card_interface(mconfig, *this)
{
}


//-------------------------------------------------
//  device_start - device-specific startup
//-------------------------------------------------

void plus4_standard_cartridge_device::device_start()
{
}


//-------------------------------------------------
//  plus4_cd_r - cartridge data read
//-------------------------------------------------

uint8_t plus4_standard_cartridge_device::plus4_cd_r(offs_t offset, uint8_t data, int ba, int cs0, int c1l, int c2l, int cs1, int c1h, int c2h)
{
	if (!c1l && m_c1l)
	{
		data = m_c1l[offset];
	}
	else if (!c1h && m_c1h)
	{
		data = m_c1h[offset];
	}
	else if (!c2l && m_c2l)
	{
		data = m_c2l[offset];
	}
	else if (!c2h && m_c2h)
	{
		data = m_c2h[offset];
	}

	return data;
}
