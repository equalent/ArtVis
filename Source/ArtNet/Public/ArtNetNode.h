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

#pragma once

#include "ArtNet.h"
#include <qudpsocket.h>
#include <memory>

#define ARTNET_PORT 6454

class ArtNetNode
{
public:
	ARTVIS_ARTNET_API ArtNetNode ();
	ARTVIS_ARTNET_API void Start ();
	ARTVIS_ARTNET_API void Stop ();

private:
	std::shared_ptr< QUdpSocket > m_Socket = nullptr;
};