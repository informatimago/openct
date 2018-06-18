#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#include <openct/path.h>
#include <openct/socket.h>
#include <openct/server.h>
#include <openct/logging.h>
#include "internal.h"


/* Reset device */
static int extern_reset (ifd_device_t * device)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}


static int extern_set_params (ifd_device_t * device, const ifd_device_params_t * parameters)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}

static int extern_get_params (ifd_device_t * device, ifd_device_params_t * parameters)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}


/* Flush any pending input */
static void extern_flush (ifd_device_t * device)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
}

static void extern_send_break (ifd_device_t * device, unsigned int flag)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
}


/*
* Send/receive data. Some devices such as USB will support
* the transceive command, others such as serial devices will
* need to use send/recv
*/
static int extern_transceive (ifd_device_t * device, const void *send, size_t send_size, void *receive, size_t receive_size, long flags)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}

static int extern_send (ifd_device_t * device, const unsigned char * send, size_t send_size)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}

static int extern_recv (ifd_device_t * device, unsigned char * receive, size_t receive_size, long flags)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}

static int extern_control (ifd_device_t * device, void * buffer, size_t buffer_size)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}

static void extern_close (ifd_device_t * device)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
}

static int extern_get_eventfd (ifd_device_t * device, short *events)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}


/* Poll for device presence. This function is called
* prior to the poll call (with revents == 0), in this
* case poll_presence is supposed to set up the poll
* structure.
* Then, it is called after poll() returns - in this case
* it should check the contents of pollfd to find out
* whether the device got removed.
*
* This is pretty much tailored for USB support, so
* the addition of PCMCIA devices may cause this
* to change.
*/
static int extern_poll_presence (ifd_device_t * device, struct pollfd * polls)
{
	fprintf(stderr,"%s()\n",__FUNCTION__);
	return -1;
}


static struct ifd_device_ops ops;

ifd_device_t *ifd_open_extern(const char *ident)
{
    ifd_device_t *dev;

    ops.reset         = extern_reset;
    ops.set_params    = extern_set_params;
    ops.get_params    = extern_get_params;
    ops.flush         = extern_flush;
    ops.send_break    = extern_send_break;
    ops.transceive    = extern_transceive;
    ops.send          = extern_send;
    ops.recv          = extern_recv;
    ops.control       = extern_control;
    ops.close         = extern_close;
    ops.get_eventfd   = extern_get_eventfd;
    ops.poll_presence = extern_poll_presence;

    dev = ifd_device_new(ident, &ops, sizeof(*dev));
    dev->hotplug = 1;
    dev->timeout = 2000;
    dev->type = IFD_DEVICE_TYPE_OTHER;
    dev->user_data = 0;

    return dev;
}
