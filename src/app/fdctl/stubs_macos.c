#include "topology.h"
#include "../../disco/topo/fd_topo.h"
#include "../../disco/topo/fd_topob.h"
#include "../../disco/topo/fd_cpu_topo.h"
#include "../../disco/keyguard/fd_keyload.h"
#include "../../disco/keyguard/fd_keyswitch.h"
#include "../../disco/keyguard/fd_keyguard_client.h"
#include "../../disco/keyguard/fd_keyguard.h"
#include "../../app/shared/commands/configure/configure.h"
#include "../../disco/net/fd_net_tile.h"
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>

struct fd_bonding_slave_iter {
  char   line[ 4096 ];
  char * saveptr;
  char * tok;
};
typedef struct fd_bonding_slave_iter fd_bonding_slave_iter_t;

/* Stubs for components that are truly Linux-only or not yet ported */

/* Agave/Ext Bank Stubs */

int fd_ext_bank_execute_and_commit_bundle( void const * bank, void * txns, ulong txn_cnt, int * out_transaction_err, uint * actual_execution_cus, uint * actual_acct_data_cus, ulong * out_timestamps, ulong * out_tips ) {
  (void)bank; (void)txns; (void)txn_cnt; (void)out_transaction_err; (void)actual_execution_cus; (void)actual_acct_data_cus; (void)out_timestamps; (void)out_tips;
  return 0;
}

int fd_ext_bank_load_account( void const * bank, int fixed_root, uchar const * addr, uchar * owner, uchar * data, ulong * data_sz ) {
  (void)bank; (void)fixed_root; (void)addr; (void)owner; (void)data; (void)data_sz;
  return -1;
}

/* Admin RPC Stubs */

int fd_ext_admin_rpc_set_identity( uchar const * identity_keypair, int is_ephemeral ) {
  (void)identity_keypair; (void)is_ephemeral;
  return 0;
}
