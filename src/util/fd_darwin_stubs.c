#include "fd_util.h"
#include <string.h>
#include "../disco/topo/fd_topo.h"
#include "../disco/topo/fd_topob.h"
#include "../disco/topo/fd_cpu_topo.h"
#include "../app/shared/commands/configure/configure.h"
#include "../vinyl/io/ur/fd_vinyl_io_ur.h"
#include "../disco/net/fd_linux_bond.h"

/* Bonding Stubs */
int          fd_bonding_is_master( char const * device ) { (void)device; return 0; }
uint         fd_bonding_slave_cnt( char const * device ) { (void)device; return 0; }
fd_bonding_slave_iter_t * fd_bonding_slave_iter_init( fd_bonding_slave_iter_t * iter, char const * device ) { (void)device; return iter; }
int          fd_bonding_slave_iter_done( fd_bonding_slave_iter_t const * iter ) { (void)iter; return 1; }
void         fd_bonding_slave_iter_next( fd_bonding_slave_iter_t * iter ) { (void)iter; }
char const * fd_bonding_slave_iter_ele( fd_bonding_slave_iter_t const * iter ) { (void)iter; return NULL; }

/* Configure Stage Stubs - Removed, linking real ones now */
static configure_result_t stub_check( config_t const * config FD_PARAM_UNUSED, int type FD_PARAM_UNUSED ) { CONFIGURE_OK(); }
configure_stage_t fd_cfg_stage_hugetlbfs        = { .name = "hugetlbfs",        .check = stub_check };
configure_stage_t fd_cfg_stage_sysctl           = { .name = "sysctl",           .check = stub_check };
configure_stage_t fd_cfg_stage_hyperthreads     = { .name = "hyperthreads",     .check = stub_check };
configure_stage_t fd_cfg_stage_bonding          = { .name = "bonding",          .check = stub_check };
configure_stage_t fd_cfg_stage_ethtool_channels = { .name = "ethtool-channels", .check = stub_check };
configure_stage_t fd_cfg_stage_ethtool_offloads = { .name = "ethtool-offloads", .check = stub_check };
configure_stage_t fd_cfg_stage_ethtool_loopback = { .name = "ethtool-loopback", .check = stub_check };

/* Netlink Topo Stubs */
ulong fd_netlink_topo_create( fd_topo_t * topo, char const * name ) { (void)topo; (void)name; return 0; }
void  fd_netlink_topo_join( fd_topo_t * topo, char const * name )   { (void)topo; (void)name; }

/* Tile Stubs */
static ulong stub_footprint( fd_topo_tile_t const * tile ) { (void)tile; return 4096UL; }
static ulong stub_align( void ) { return 128UL; }

fd_topo_run_tile_t fd_tile_netlnk  = {
  .name              = "netlnk",
  .scratch_footprint = stub_footprint,
  .scratch_align     = stub_align
};
fd_topo_run_tile_t fd_tile_net     = {
  .name              = "net",
  .scratch_footprint = stub_footprint,
  .scratch_align     = stub_align
};

/* CPU Topo Stubs */
void fd_topo_cpus_init( fd_topo_cpus_t * cpus ) {
  memset( cpus, 0, sizeof(fd_topo_cpus_t) );
  cpus->cpu_cnt = 128;
  cpus->numa_node_cnt = 1;
  for( ulong i=0; i<cpus->cpu_cnt; i++ ) {
    cpus->cpu[i].idx = i;
    cpus->cpu[i].online = 1;
    cpus->cpu[i].numa_node = 0;
    cpus->cpu[i].sibling = ULONG_MAX;
  }
}

/* Vinyl IO UR Stubs */
ulong fd_vinyl_io_ur_align( void ) { return 4096UL; }
ulong fd_vinyl_io_ur_footprint( ulong spad_max ) { (void)spad_max; return 4096UL; }
fd_vinyl_io_t * fd_vinyl_io_ur_init( void * mem, ulong spad_max, int dev_fd, void * ring ) {
  (void)mem; (void)spad_max; (void)dev_fd; (void)ring;
  return NULL;
}

/* Other Stubs */
void fd_topo_install_xdp_simple( void * topo, void * addr ) { (void)topo; (void)addr; }
