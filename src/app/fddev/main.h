#ifndef HEADER_fd_src_app_fddev_main_h
#define HEADER_fd_src_app_fddev_main_h

#include "../shared/commands/configure/configure.h"

extern char const * FD_APP_NAME;
extern char const * FD_BINARY_NAME;

extern fd_topo_obj_callbacks_t fd_obj_cb_mcache;
extern fd_topo_obj_callbacks_t fd_obj_cb_dcache;
extern fd_topo_obj_callbacks_t fd_obj_cb_fseq;
extern fd_topo_obj_callbacks_t fd_obj_cb_metrics;
extern fd_topo_obj_callbacks_t fd_obj_cb_dbl_buf;
extern fd_topo_obj_callbacks_t fd_obj_cb_neigh4_hmap;
extern fd_topo_obj_callbacks_t fd_obj_cb_fib4;
extern fd_topo_obj_callbacks_t fd_obj_cb_keyswitch;
extern fd_topo_obj_callbacks_t fd_obj_cb_tile;

extern fd_topo_obj_callbacks_t * CALLBACKS[];


extern configure_stage_t fd_cfg_stage_kill;
extern configure_stage_t fd_cfg_stage_genesis;
extern configure_stage_t fd_cfg_stage_keys;
extern configure_stage_t fd_cfg_stage_blockstore;

extern configure_stage_t * STAGES[];


extern fd_topo_run_tile_t fd_tile_net;
extern fd_topo_run_tile_t fd_tile_netlnk;
extern fd_topo_run_tile_t fd_tile_sock;
extern fd_topo_run_tile_t fd_tile_quic;
extern fd_topo_run_tile_t fd_tile_bundle;
extern fd_topo_run_tile_t fd_tile_verify;
extern fd_topo_run_tile_t fd_tile_dedup;
extern fd_topo_run_tile_t fd_tile_pack;
extern fd_topo_run_tile_t fd_tile_shred;
extern fd_topo_run_tile_t fd_tile_sign;
extern fd_topo_run_tile_t fd_tile_metric;
extern fd_topo_run_tile_t fd_tile_diag;
extern fd_topo_run_tile_t fd_tile_gui;
extern fd_topo_run_tile_t fd_tile_plugin;
extern fd_topo_run_tile_t fd_tile_bencho;
extern fd_topo_run_tile_t fd_tile_benchg;
extern fd_topo_run_tile_t fd_tile_benchs;
extern fd_topo_run_tile_t fd_tile_pktgen;
extern fd_topo_run_tile_t fd_tile_resolh;
extern fd_topo_run_tile_t fd_tile_pohh;
extern fd_topo_run_tile_t fd_tile_bank;
extern fd_topo_run_tile_t fd_tile_store;
extern fd_topo_run_tile_t fd_tile_udpecho;

extern fd_topo_run_tile_t * TILES[];


extern action_t fd_action_run;
extern action_t fd_action_run1;
extern action_t fd_action_run_agave;
extern action_t fd_action_configure;
extern action_t fd_action_monitor;
extern action_t fd_action_keys;
extern action_t fd_action_ready;
extern action_t fd_action_mem;
extern action_t fd_action_netconf;
extern action_t fd_action_set_identityh;
extern action_t fd_action_get_identity;
extern action_t fd_action_version;
extern action_t fd_action_bench;
extern action_t fd_action_bundle_client;
extern action_t fd_action_dev;
extern action_t fd_action_dev1;
extern action_t fd_action_dump;
extern action_t fd_action_flame;
extern action_t fd_action_help;
extern action_t fd_action_metrics;
extern action_t fd_action_load;
extern action_t fd_action_pktgen;
extern action_t fd_action_quic_trace;
extern action_t fd_action_txn;
extern action_t fd_action_udpecho;
extern action_t fd_action_wksp;

extern action_t * ACTIONS[];


#endif /* HEADER_fd_src_app_fddev_main_h */
