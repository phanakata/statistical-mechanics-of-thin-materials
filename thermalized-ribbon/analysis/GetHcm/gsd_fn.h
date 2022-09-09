static int __gsd_expand_index(struct gsd_handle *);
uint16_t __gsd_get_id(struct gsd_handle *, const char *, uint8_t);
int __gsd_initialize_file(int, const char *, const char *, uint32_t);
int __gsd_read_header(struct gsd_handle*);
uint32_t gsd_make_version(unsigned int, unsigned int);
int gsd_create(const char *, const char *, const char *, uint32_t);
int gsd_create_and_open(struct gsd_handle*,
                        const char *,
                        const char *,
                        const char *,
                        uint32_t ,
                        const enum gsd_open_flag flags,
                        int);

int gsd_open(struct gsd_handle* , const char *, const enum gsd_open_flag flags);
int gsd_truncate(struct gsd_handle* );
int gsd_close(struct gsd_handle* );
int gsd_end_frame(struct gsd_handle*);
int gsd_write_chunk(struct gsd_handle* ,
                    const char *,
                    enum gsd_type type,
                    uint64_t ,
                    uint32_t ,
                    uint8_t ,
                    const void *);
uint64_t gsd_get_nframes(struct gsd_handle* );
const struct gsd_index_entry* gsd_find_chunk(struct gsd_handle*, uint64_t, const char *);
int gsd_read_chunk(struct gsd_handle* , void* , const struct gsd_index_entry*);
size_t gsd_sizeof_type(enum gsd_type type);
