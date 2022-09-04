{
  "targets": [
    {
      "target_name": "diag_stamp",
      "cflags!": ["-fno-exception"],
      "cflags_cc!": ["-fno-exception"],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "sources": [ "diag_stamp.c", "diag_stamp_wrapper.cc" ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
    }
  ]
}
