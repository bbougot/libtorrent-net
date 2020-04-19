#pragma once
#include <vector>

namespace libtorrent
{
    class session;
    struct torrent_handle;
	inline namespace v1_2
	{
        struct add_torrent_params;
	}
}

namespace ltnetsession
{
    class session_native
    {
    public:
        session_native();
        ~session_native();

        std::vector<libtorrent::torrent_handle> get_torrents();
        libtorrent::torrent_handle add_torrent(libtorrent::v1_2::add_torrent_params& params);
        void remove_torrent(libtorrent::torrent_handle& handle);
    private:
        libtorrent::session* session_;
    };
}
