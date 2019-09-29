#pragma once

namespace libtorrent
{
    struct announce_entry;
}

namespace ltnet
{
    public ref class announce_entry
    {
    internal:
        announce_entry(libtorrent::announce_entry& entry);
        libtorrent::announce_entry* ptr();

    public:
        announce_entry(System::String^ url);
        ~announce_entry();
		!announce_entry();

        int next_announce_in();
        int min_announce_in();
        void reset();
        bool can_announce(System::DateTime now, bool is_seed);
        bool is_working();
        void trim();

        property System::String^ url { System::String^ get(); }
        property System::String^ trackerid { System::String^ get(); }
        property System::String^ message { System::String^ get(); }
        property int scrape_incomplete { int get(); }
        property int scrape_complete { int get(); }
        property int scrape_downloaded { int get(); }
        property int tier { int get(); }
        property int fail_limit { int get(); }
        property int fails { int get(); }
        property bool updating { bool get(); }
        property int source { int get(); }
        property bool verified { bool get(); }
        property bool start_sent { bool get(); }
        property bool complete_sent { bool get(); }
        property bool send_stats { bool get(); }

    private:
        libtorrent::announce_entry* entry_;
    };
}
