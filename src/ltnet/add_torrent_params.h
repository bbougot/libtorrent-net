#pragma once

namespace libtorrent
{
	inline namespace v1_2
	{
        struct add_torrent_params;
	}
}

namespace ltnet
{
    ref class TorrentInfo;
    public ref class AddTorrentParams
    {
    public:
        AddTorrentParams();
        ~AddTorrentParams();
		!AddTorrentParams();

        property System::String^ save_path
        {
            System::String^ get();
            void set(System::String^ value);
        }

        property TorrentInfo^ ti
        {
            TorrentInfo^ get();
            void set(TorrentInfo^ value);
        }

    internal:
        libtorrent::v1_2::add_torrent_params* ptr();

    private:
        libtorrent::v1_2::add_torrent_params* params_;
    };
}
