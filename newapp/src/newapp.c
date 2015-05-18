#include <kore/kore.h>
#include <kore/http.h>

#include "assets.h"
int page(struct http_request *);
int serve_kore(struct http_request *);

int
page(struct http_request *req)
{
  kore_log(1, "Request dude!");
	http_response(req, 200, asset_index_html, asset_len_index_html);
	return (KORE_RESULT_OK);
}

int
serve_kore(struct http_request *req)
{
  http_response_header(req, "content-type", "image/png");
  http_response(req, 200, asset_kore_png, asset_len_kore_png);

  return (KORE_RESULT_OK);
}