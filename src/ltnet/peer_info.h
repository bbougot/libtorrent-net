#pragma once

namespace libtorrent
{
    inline namespace v1_2
    {
        struct peer_info;
    }
}

namespace ltnet
{
    public ref class PeerInfo
    {
    internal:
        PeerInfo(libtorrent::v1_2::peer_info& info);

    public:
        ~PeerInfo();
		!PeerInfo();

    private:
        libtorrent::v1_2::peer_info* info_;
    };
}
