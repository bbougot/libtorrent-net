#include "entry.h"

#include <libtorrent/entry.hpp>

using namespace ltnet;

entry::entry(const libtorrent::entry& e)
{
    entry_ = new libtorrent::entry(e);
}

entry::~entry()
{
	this->!entry();
}

entry::!entry()
{
	delete entry_;
}

libtorrent::entry* entry::ptr()
{
    return entry_;
}
