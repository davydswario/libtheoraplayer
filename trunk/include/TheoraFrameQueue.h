/************************************************************************************
This source file is part of the Theora Video Playback Library
For latest info, see http://libtheoraplayer.sourceforge.net/
*************************************************************************************
Copyright (c) 2008-2009 Kresimir Spes (kreso@cateia.com)

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License (LGPL) as published by the 
Free Software Foundation; either version 2 of the License, or (at your option) 
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
*************************************************************************************/

#ifndef _TheoraFrameQueue_h
#define _TheoraFrameQueue_h

#include "TheoraAsync.h"

class TheoraVideoFrame;
class TheoraVideoClip;

/**
	
*/
class TheoraFrameQueue
{
	TheoraVideoFrame** mQueue;
	int mSize;
	TheoraVideoClip* mParent;
	TheoraMutex mMutex;
public:
	TheoraFrameQueue(int n,TheoraVideoClip* parent);
	~TheoraFrameQueue();

	TheoraVideoFrame* getFirstAvailableFrame();

	int getUsedCount();

	void pop();
	void clear(); //! frees all decoded frames for reuse (does not destroy memory, just marks them as free)
	//! Called by WorkerThreads when they need to unload frame data
	TheoraVideoFrame* requestEmptyFrame();
	

	void setSize(int n);
	int getSize();
};

#endif
