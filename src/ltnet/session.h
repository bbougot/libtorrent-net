#pragma once

namespace ltnetsession
{
    class session_native;
}

namespace ltnet
{
    ref class TorrentHandle;
    ref class AddTorrentParams;
    public ref class Session
    {
    public:
        Session();
        ~Session();
		!Session();

        cli::array<TorrentHandle^>^ get_torrents();
        TorrentHandle^ add_torrent(AddTorrentParams^ params);
        void remove_torrent(TorrentHandle^ handle);
    private:
        ltnetsession::session_native* session_;
    };
}
