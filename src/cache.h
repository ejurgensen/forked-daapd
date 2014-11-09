
#ifndef __CACHE_H__
#define __CACHE_H__

#ifdef HAVE_LIBEVENT2
# include <event2/event.h>
# include <event2/buffer.h>
#else
# include <event.h>
#endif


/* ---------------------------- DAAP cache API  --------------------------- */

void
cache_daap_trigger(void);

int
cache_daap_get(const char *query, struct evbuffer *evbuf);

void
cache_daap_add(const char *query, const char *ua, int msec);

int
cache_daap_threshold(void);


/* ---------------------------- Artwork cache API  --------------------------- */

int
cache_artwork_ping(char *path, time_t mtime);

int
cache_artwork_delete_by_path(char *path);

int
cache_artwork_purge_cruft(time_t ref);

int
cache_artwork_add(int64_t persistentid, int max_w, int max_h, int format, char *filename, struct evbuffer *evbuf);

int
cache_artwork_get(int64_t persistentid, int max_w, int max_h, int *cached, int *format, struct evbuffer *evbuf);


/* ---------------------------- Cache API  --------------------------- */

int
cache_init(void);

void
cache_deinit(void);

#endif /* !__CACHE_H__ */
