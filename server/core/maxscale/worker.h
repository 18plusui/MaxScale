#pragma once
/*
 * Copyright (c) 2016 MariaDB Corporation Ab
 *
 * Use of this software is governed by the Business Source License included
 * in the LICENSE.TXT file and at www.mariadb.com/bsl11.
 *
 * Change Date: 2019-07-01
 *
 * On the date above, in accordance with the Business Source License, use
 * of this software will be governed by version 2 or later of the General
 * Public License.
 */

#include <maxscale/worker.h>

MXS_BEGIN_DECLS

/**
 * Initialize the worker mechanism.
 *
 * To be called once at process startup. This will cause as many workers
 * to be created as the number of threads defined.
 */
void mxs_worker_init();

/**
 * Finalize the worker mechanism.
 *
 * To be called once at process shutdown. This will cause all workers
 * to be destroyed. When the function is called, no worker should be
 * running anymore.
 */
void mxs_worker_finish();

/**
 * Main function of worker.
 *
 * This worker will run the poll loop, until it is told to shut down.
 *
 * @param worker  The worker.
 */
void mxs_worker_main(MXS_WORKER* worker);

/**
 * Start worker in separate thread.
 *
 * This function will start a new thread, in which the `mxs_worker_main`
 * function will be executed.
 *
 * @return True if the thread could be started, false otherwise.
 */
bool mxs_worker_start(MXS_WORKER* worker);

/**
 * Waits for the worker to finish.
 *
 * @param worker  The worker to wait for.
 */
void mxs_worker_join(MXS_WORKER* worker);

MXS_END_DECLS
