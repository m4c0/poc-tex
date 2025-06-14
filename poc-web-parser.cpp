#pragma leco tool

import jojo;
import print;

static const char * g_ptr;

static void process_tex();

static auto take() { return *g_ptr ? *g_ptr++ : '\0'; }

static void until_eol() {
  while (*g_ptr && *g_ptr != '\n') take();
  take(); // consume EOL
}
static void word() {
  while (*g_ptr) {
    auto c = take();
    if (c >= 'A' && c <= 'Z') continue;
    if (c >= 'a' && c <= 'z') continue;
    g_ptr--;
    break;
  }
}

static void process_tex() {
  while (*g_ptr) {
    switch (take()) {
      case '\n': break;
      case '\\': word(); break;
      case ' ': break;
      case '%': until_eol(); break;
      case '@': die("@", take()); break;
      case '{': break;
      case '}': break; // TODO: balance?
      default: break;
    }
  }
}

int main() try {
  auto src = jojo::read_cstr("tex.web");

  g_ptr = src.begin();
  process_tex();
} catch (...) {
  return 1;
}
