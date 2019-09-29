#pragma once

namespace libtorrent
{
    struct torrent_handle;
}

namespace ltnet
{
    ref class announce_entry;
    ref class peer_info;
    ref class torrent_info;
    ref class torrent_status;

    public ref class torrent_handle
    {
    internal:
        torrent_handle(libtorrent::torrent_handle& handle);
        libtorrent::torrent_handle* ptr();

    public:
        ~torrent_handle();
		!torrent_handle();
        void add_piece(int piece, cli::array<System::Byte>^ data, int flags);
        void read_piece(int index);
        bool have_piece(int index);
        cli::array<peer_info^>^ get_peer_info();
        torrent_status^ status();
        void reset_piece_deadline(int index);
        void clear_piece_deadlines();
        void set_piece_deadline(int index, int deadline);
        void set_priority(int priority);
        cli::array<long long>^ file_progress(int flags);
        void clear_error();
        cli::array<announce_entry^>^ trackers();
        void add_tracker(announce_entry^ entry);
        void add_url_seed(System::String^ url);
        void remove_url_seed(System::String^ url);
        cli::array<System::String^>^ url_seeds();
        void add_http_seed(System::String^ url);
        void remove_http_seed(System::String^ url);
        cli::array<System::String^>^ http_seeds();
        void set_metadata(cli::array<System::Byte>^ metadata);
        bool is_valid();
        void pause();
        void resume();
        void set_upload_mode(bool b);
        void set_share_mode(bool b);
        void flush_cache();
        void apply_ip_filter(bool b);
        void force_recheck();
        void save_resume_data(int flags);
        bool need_save_resume_data();
        void auto_managed(bool b);
        void queue_position_down();
        void queue_position_top();
        int queue_position();
        void queue_position_bottom();
        void queue_position_up();
        torrent_info^ torrent_file();
        cli::array<int>^ piece_availability();
        int piece_priority(int index);
        void piece_priority(int index, int priority);
        cli::array<int>^ piece_priorities();
        int file_priority(int index);
        void prioritize_files(cli::array<int>^ files);
        void file_priority(int index, int priority);
        cli::array<int>^ file_priorities();
        void force_reannounce(int seconds, int tracker_index);
        void force_dht_announce();
        void scrape_tracker();
        int upload_limit();
        int download_limit();
        void set_upload_limit(int limit);
        void set_download_limit(int limit);
        void set_sequential_download(bool s);
        int max_uploads();
        void set_max_uploads(int max_uploads);
        int max_connections();
        void set_max_connections(int max_connections);
        void move_storage(System::String^ save_path, int flags); 
        void rename_file(int index, System::String^ name);
        void super_seeding(bool on);
		System::String^ info_hash();

    private:
        libtorrent::torrent_handle* handle_;
    };
}
