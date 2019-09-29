#pragma once

namespace libtorrent
{
    class session;
}

namespace ltnet
{
    ref class add_torrent_params;
    ref class entry;
    ref class torrent_handle;

    public ref class session
    {
    public:
		session();
        ~session();
		!session();

        cli::array<torrent_handle^>^ get_torrents();
        void async_add_torrent(add_torrent_params^ params);
        torrent_handle^ add_torrent(add_torrent_params^ params);
        void pause();
        void resume();
        bool is_paused();
        void set_key(int key);
        bool is_listening();
        int listen_port();
        void remove_torrent(torrent_handle^ handle, int options);
    private:
        libtorrent::session* session_;
    };
}
