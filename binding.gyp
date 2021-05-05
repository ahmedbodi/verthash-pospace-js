{
  "targets": [
    {
      "target_name": "verthash-pospace",
      "sources": [
	"verthash.cc",
	"h1.c",
	"h1.h",
	"h2.c",
	"h2.h",
	"tiny_sha3/sha3.c",
	"tiny_sha3/sha3.h",
      ],
      "include_dirs": [
        "tiny_sha3",
        "<!(node -e \"require('nan')\")"
      ],
      "cflags_cc": [
        "-std=c++11"
      ]
    }
  ]
}
