/*
    This file is part of ArtVis.

    ArtVis is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ArtVis is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ArtVis.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "..\Public\ArtNetNode.h"

ArtNetNode::ArtNetNode ()
{

}

void ArtNetNode::Start ()
{
	qDebug() << "Opening ArtNet socket...";
	m_Socket = std::make_unique<QUdpSocket> ();
	m_Socket->bind ( QHostAddress::Any, ARTNET_PORT, QAbstractSocket::BindFlag::ReuseAddressHint );
}

void ArtNetNode::Stop ()
{
	qDebug () << "Closing ArtNet socket...";
	m_Socket.reset ();
}
