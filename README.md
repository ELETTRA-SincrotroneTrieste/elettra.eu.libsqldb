# elettra.eu.libsqldb
CPP base library for sql database access

## Prerequisites

- *meson / ninja * build system
- *mariadb* dependency

## Building and installing

Clone the repository

> git clone https://github.com/ELETTRA-SincrotroneTrieste/elettra.eu.libsqldb

> cd elettra.eu.libsqldb

Generate the *meson build* directory:

> meson builddir

> cd builddir

Configure the build options: 

> meson configure -Dprefix=/usr/local/elettra.eu.libsqldb

> meson configure -Dlibdir=lib

Debug or release?

> meson configure -Dbuildtype=debug

or

> meson configure -Dbuildtype=release

Build and install:

> ninja && ninja install

Do not forget to export

> export LD_LIBRARY_PATH=/usr/local/elettra.eu.libsqldb/lib:$LD_LIBRARY_PATH

and, when building against *elettra.eu.libsqldb*, for example the [hdbextractor](https://github.com/ELETTRA-SincrotroneTrieste/hdbextractor) library:

> export PKG_CONFIG_PATH=/usr/local/elettra.eu.libsqldb/lib/pkgconfig:$PKG_CONFIG_PATH

## See also

- The [hdb extractor library](https://github.com/ELETTRA-SincrotroneTrieste/hdbextractor)
- The [cumbia libraries](https://github.com/ELETTRA-SincrotroneTrieste/cumbia-libs)
- The [cumbia hdb extractor plugin](https://github.com/ELETTRA-SincrotroneTrieste/cumbia-historicaldb)


