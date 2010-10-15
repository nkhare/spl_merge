/*****************************************************************************\
 *  Copyright (C) 2007-2010 Lawrence Livermore National Security, LLC.
 *  Copyright (C) 2007 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Brian Behlendorf <behlendorf1@llnl.gov>.
 *  UCRL-CODE-235197
 *
 *  This file is part of the SPL, Solaris Porting Layer.
 *  For details, see <http://github.com/behlendorf/spl/>.
 *
 *  The SPL is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  The SPL is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with the SPL.  If not, see <http://www.gnu.org/licenses/>.
\*****************************************************************************/

#ifndef _SPL_FILE_COMPAT_H
#define _SPL_FILE_COMPAT_H

#include <linux/fs.h>
#ifdef HAVE_FDTABLE_HEADER
#include <linux/fdtable.h>
#endif

static inline struct file *
spl_filp_open(const char *name, int flags, int mode, int *err)
{
        struct file *filp = NULL;
        int rc;

        filp = filp_open(name, flags, mode);
        if (IS_ERR(filp)) {
                rc = PTR_ERR(filp);
                if (err)
                        *err = rc;
                filp = NULL;
        }
        return filp;
}

#define spl_filp_close(f)		filp_close(f, NULL)
#define spl_filp_poff(f)		(&(f)->f_pos)
#define spl_filp_write(fp, b, s, p)	(fp)->f_op->write((fp), (b), (s), p)

#ifdef HAVE_3ARGS_FILE_FSYNC
#define spl_filp_fsync(fp, sync)	(fp)->f_op->fsync((fp), \
					(fp)->f_dentry, sync)
#else
#define spl_filp_fsync(fp, sync)	(fp)->f_op->fsync((fp), sync)
#endif

#endif /* SPL_FILE_COMPAT_H */

