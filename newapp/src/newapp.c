#include <kore/kore.h>
#include <kore/http.h>
#include "base_pablo.h"
#include "assets.h"
int serve_index(struct http_request *);
int serve_kore(struct http_request *);
int serve_static(struct http_request *);

int
serve_index(struct http_request *req)
{
  kore_log(1, "Request dude!");
	http_response(req, 200, asset_index_html, asset_len_index_html);
	return (KORE_RESULT_OK);
}

int
serve_static(struct http_request *req)
{
  char filename[7 + strlen(req->path)];
  sprintf(filename, "assets%s", req->path);

  kore_log(1, filename);
  char *file_buffer = read_file(filename);
  long file_length = file_size(filename);
  if (file_buffer && file_length != -1)
  {
    http_response(req, 200, file_buffer, file_length);
  }
  else
  {
    http_response(req, 404, asset_404_html, asset_len_404_html); 
  }
  return (KORE_RESULT_OK);
}