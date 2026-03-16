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

/* Tile Stubs */

fd_topo_run_tile_t fd_tile_netlnk  = { .name = "netlnk"  };
fd_topo_run_tile_t fd_tile_net     = { .name = "net"     };
/* Redundant tiles now built in libfddev_shared or libfd_disco:pktgen, udpecho, sign, diag, plugin, resolh, store, bencho, benchg, benchs */

/* Netlink Topo Stubs */

ulong fd_netlink_topo_create( fd_topo_t * topo, char const * name ) { (void)topo; (void)name; return 0; }
void  fd_netlink_topo_join( fd_topo_t * topo, char const * name )   { (void)topo; (void)name; }

/* CPU Topo Stubs */

void fd_topo_cpus_init( fd_topo_cpus_t * cpus ) {
  memset( cpus, 0, sizeof(fd_topo_cpus_t) );
  cpus->cpu_cnt = 1;
  cpus->cpu[0].online = 1;
}

/* Stubs for components that are truly Linux-only or not yet ported */

/* [REMOVED REDUNDANT STUBS] */

/* Agave/Ext Bank Stubs */

int fd_ext_bank_execute_and_commit_bundle( void const * bank, void * txns, ulong txn_cnt, int * out_transaction_err, uint * actual_execution_cus, uint * actual_acct_data_cus, ulong * out_timestamps, ulong * out_tips ) {
  (void)bank; (void)txns; (void)txn_cnt; (void)out_transaction_err; (void)actual_execution_cus; (void)actual_acct_data_cus; (void)out_timestamps; (void)out_tips;
  return 0;
}

int fd_ext_bank_load_account( void const * bank, int fixed_root, uchar const * addr, uchar * owner, uchar * data, ulong * data_sz ) {
  (void)bank; (void)fixed_root; (void)addr; (void)owner; (void)data; (void)data_sz;
  return -1;
}

/* Configure Stage Stubs */

static int                stub_enabled  ( config_t const * config ) { (void)config; return 1; }
static void               stub_init_perm( fd_cap_chk_t * chk, config_t const * config ) { (void)chk; (void)config; }
static void               stub_fini_perm( fd_cap_chk_t * chk, config_t const * config ) { (void)chk; (void)config; }
static void               stub_init     ( config_t const * config ) { (void)config; }
static int                stub_fini     ( config_t const * config, int pre_init ) { (void)config; (void)pre_init; return 0; }
static configure_result_t stub_check    ( config_t const * config, int check_type ) { (void)config; (void)check_type; configure_result_t res; res.result = CONFIGURE_OK; res.message[0] = '\0'; return res; }

#define STUB_STAGE(name_str) { \
  .name = name_str, \
  .always_recreate = 0, \
  .enabled = stub_enabled, \
  .init_perm = stub_init_perm, \
  .fini_perm = stub_fini_perm, \
  .init = stub_init, \
  .fini = stub_fini, \
  .check = stub_check \
}

configure_stage_t fd_cfg_stage_hugetlbfs        = STUB_STAGE("hugetlbfs");
configure_stage_t fd_cfg_stage_sysctl           = STUB_STAGE("sysctl");
configure_stage_t fd_cfg_stage_hyperthreads     = STUB_STAGE("hyperthreads");
configure_stage_t fd_cfg_stage_bonding          = STUB_STAGE("bonding");
configure_stage_t fd_cfg_stage_ethtool_channels = STUB_STAGE("ethtool-channels");
configure_stage_t fd_cfg_stage_ethtool_offloads = STUB_STAGE("ethtool-offloads");
configure_stage_t fd_cfg_stage_ethtool_loopback = STUB_STAGE("ethtool-loopback");
/* Action Stubs */

/* Redundant actions now built: configure, bench, pktgen, udpecho */

/* Bonding Stubs */

fd_bonding_slave_iter_t * fd_bonding_slave_iter_init( fd_bonding_slave_iter_t * iter, char const * device ) { (void)device; return iter; }
int    fd_bonding_slave_iter_done( fd_bonding_slave_iter_t const * iter ) { (void)iter; return 1; }
void   fd_bonding_slave_iter_next( fd_bonding_slave_iter_t * iter ) { (void)iter; }
char const * fd_bonding_slave_iter_ele( fd_bonding_slave_iter_t const * iter ) { (void)iter; return NULL; }
int    fd_bonding_is_master( char const * device ) { (void)device; return 0; }

/* Admin RPC Stubs */

int fd_ext_admin_rpc_set_identity( uchar const * identity_keypair, int is_ephemeral ) {
  (void)identity_keypair; (void)is_ephemeral;
  return 0;
}

/* Vinyl and Snapshot stages are now built for Darwin */

/* Other Stubs */

/* Other Stubs */

void fd_topo_install_xdp_simple( void * topo, void * addr ) { (void)topo; (void)addr; }
