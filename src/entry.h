#pragma once

namespace libtorrent
{
    class entry;
}

namespace ltnet
{
    public ref class entry
    {
    internal:
        entry(const libtorrent::entry& e);
        libtorrent::entry* ptr();

    public:
        ~entry();
		!entry();

    private:
        libtorrent::entry* entry_;
    };
}
