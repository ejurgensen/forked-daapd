
#ifndef __HTTPD_H__
#define __HTTPD_H__

#include <event2/http.h>
#include <event2/buffer.h>

void
httpd_stream_file(struct evhttp_request *req, int id);

void
httpd_send_reply(struct evhttp_request *req, int code, const char *reason, struct evbuffer *evbuf);

void
httpd_send_error(struct evhttp_request* req, int error, const char* reason);

void
httpd_handle_cors_simple(struct evhttp_request *req);

int
httpd_handle_cors_preflight(struct evhttp_request *req);

char *
httpd_fixup_uri(struct evhttp_request *req);

int
httpd_basic_auth(struct evhttp_request *req, char *user, char *passwd, char *realm);

int
httpd_init(void);

void
httpd_deinit(void);

#endif /* !__HTTPD_H__ */
