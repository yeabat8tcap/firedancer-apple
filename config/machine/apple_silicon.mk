# Firedancer machine configuration for Apple Silicon (M4 Max)

# We use Clang by default on macOS
CC=clang
CXX=clang++
LD=clang++

# Machine-specific directories
BUILDDIR?=apple_silicon/$(notdir $(CC))

include config/base.mk
include config/extra/with-clang.mk
include config/extra/with-brutality.mk
include config/extra/with-optimization.mk
include config/extra/with-debug.mk
include config/extra/with-security.mk
include config/extra/with-threads.mk

# Basic hosted/thread support
FD_HAS_HOSTED:=1
FD_HAS_THREADS:=1
FD_HAS_ALLOCA:=1
FD_HAS_DARWIN:=1
CPPFLAGS+=-DFD_HAS_HOSTED=1
CPPFLAGS+=-DFD_HAS_THREADS=1
CPPFLAGS+=-DFD_HAS_ALLOCA=1
CPPFLAGS+=-DFD_HAS_DARWIN=1

# Dependencies
FD_HAS_ZSTD:=1
FD_HAS_LZ4:=1
FD_HAS_BLST:=1
FD_HAS_OPENSSL:=1
FD_HAS_S2NBIGNUM:=1
FD_HAS_BZIP2:=1

CPPFLAGS+=-DFD_HAS_ZSTD=1
CPPFLAGS+=-DFD_HAS_LZ4=1
CPPFLAGS+=-DFD_HAS_BLST=1
CPPFLAGS+=-DFD_HAS_OPENSSL=1
CPPFLAGS+=-DFD_HAS_S2NBIGNUM=1

# Library flags
ZSTD_LIBS:=-lzstd
LZ4_LIBS:=-llz4
BLST_LIBS:=-lblst
OPENSSL_LIBS:=-lssl -lcrypto
S2NBIGNUM_LIBS:=-L./opt/lib -ls2n-bignum
BZIP2_LIBS:=-lbz2

# Global flags
CPPFLAGS += -DFD_HAS_ZSTD=1 -DFD_HAS_LZ4=1 -DFD_HAS_BLST=1 -DFD_HAS_OPENSSL=1 -DFD_HAS_S2NBIGNUM=1 -DFD_HAS_BZIP2=1
CPPFLAGS += -I/opt/homebrew/opt/secp256k1/include -I/opt/homebrew/opt/bzip2/include

LDFLAGS  += -L./opt/lib -lzstd -llz4 -lblst -lssl -lcrypto -ls2n-bignum -lbz2
LDFLAGS  += -L/opt/homebrew/opt/secp256k1/lib -lsecp256k1
LDFLAGS  += -L/opt/homebrew/opt/bzip2/lib

# Architecture support (ARM64)
FD_HAS_ARM:=1
FD_HAS_NEON:=1
FD_HAS_INT128:=1
FD_HAS_DOUBLE:=1
CPPFLAGS+=-DFD_HAS_ARM=1
CPPFLAGS+=-DFD_HAS_NEON=1
CPPFLAGS+=-DFD_HAS_INT128=1
CPPFLAGS+=-DFD_HAS_DOUBLE=1

# M4 Max Specific Tuning (march=native should work for Clang on macOS)
CPPFLAGS+=-march=native
RUSTFLAGS+=-C target-cpu=native

# macOS Specific Flags
CPPFLAGS+=-D__MACH__=1
CPPFLAGS+=-D_DARWIN_C_SOURCE
CPPFLAGS+=-Wno-format
LDFLAGS+=-framework Security -framework CoreFoundation -framework SystemConfiguration

# Informational
$(info Using MACHINE=apple_silicon)
$(info Using FD_HAS_ARM=1)
$(info Using FD_HAS_NEON=1)
$(info Using FD_HAS_THREADS=1)
