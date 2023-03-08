#include"monom.h"







monom::monom(double m_data, int m_xyz, monom* m_next)
{
	data = m_data;
	xyz = m_xyz;
	next = m_next;
}


monom::monom(double m_data, int m_xyz)
{
	data = m_data;
	xyz = m_xyz;
}