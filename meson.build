project('elettra.eu.libsqldb', 'cpp', version : '1.0.0',
    default_options : ['c_std=c17', 'cpp_std=c++17'])

project_description = 'c++ framework to access sql databases'

libsqldb_version = meson.project_version() # set in project() below
ver_arr = libsqldb_version.split('.')

libsqldb_major_version = ver_arr[0]
libsqldb_minor_version = ver_arr[1]
libsqldb_micro_version = ver_arr[2]

conf = configuration_data()
# Surround the version in quotes to make it a C string
conf.set_quoted('VERSION', libsqldb_version)
configure_file(output : 'config.h',
               configuration : conf)


headers = [
'src/queryconfiguration.h',
'src/dbsettings.h',
'src/mysql/mysqlrow.h',
'src/mysql/mysqlresult.h',
'src/mysql/mysqlconnection.h',
'src/mysql/mysqlutils.h',
'src/configurationparser.h',
'src/db/dbschema.h',
'src/db/row.h',
'src/db/xvariantprivate.h',
'src/db/result.h',
'src/db/xvariantdatainfo.h',
'src/db/resultlistenerinterface.h',
'src/db/timeinterval.h',
'src/db/connection.h',
'src/db/xvariantlist.h',
'src/db/dbschemaprivate.h',
'src/db/configurabledbschema.h',
'src/db/helpers/configurabledbschemahelper.h',
'src/db/xvariant.h',
'src/db/datetimeutils.h',
'src/dbmacros.h',
'src/utils/xvariantprinter.h',
'src/sharedpointer.h',
]

install_headers(headers, subdir : 'libsqldb') # -> include/libsqldb/

sources = [
'src/dbsettings.cpp',
'src/configurationparser.cpp',
'src/mysql/mysqlrow.cpp',
'src/mysql/mysqlutils.cpp',
'src/mysql/mysqlconnection.cpp',
'src/mysql/mysqlresult.cpp',
'src/queryconfiguration.cpp',
'src/db/xvariantlist.cpp',
'src/db/result.cpp',
'src/db/datetimeutils.cpp',
'src/db/configurabledbschema.cpp',
'src/db/timeinterval.cpp',
'src/db/xvariantdatainfo.cpp',
'src/db/xvariant.cpp',
'src/db/xvariantprivate.cpp',
'src/db/row.cpp',
'src/db/helpers/configurabledbschemahelper.cpp',
'src/utils/xvariantprinter.cpp',
'src/sharedpointer.cpp'
]

includedirs = include_directories('src', 'src/mysql', 'src/utils', 'src/db/helpers', 'src/db')

# for perr, pinfo, etc
cpp_arguments = [ '-DELETTRA_EU_LIBSQLDB_PRINTINFO=1' ]

deps = [ dependency('mysqlclient') ]

libsqldblib = shared_library('libsqldb', sources,
        version : meson.project_version(),
        include_directories : includedirs,
        cpp_args : cpp_arguments,
        dependencies : deps,
        install : true)

### ====================================== pkg config   ============================
pkgconfig = find_program('pkg-config', required: false)
if not pkgconfig.found()
  error('MESON_SKIP_TEST: pkg-config not found')
endif

pkgg = import('pkgconfig')

h = ['libsqldb']  # subdirectories of ${prefix}/${includedir} to add to header path
pkgg.generate(
    libraries : libsqldblib,
    subdirs : h,
    version : meson.project_version(),
    name : 'libsqldb',
    filebase : 'libsqldb',
    requires: ['mysqlclient'],
    description : project_description )


### ====================================== documentation ===========================
doxygen = find_program('doxygen', required : false)
if not doxygen.found()
  error('MESON_SKIP_TEST doxygen not found.')
endif
  doxydata = configuration_data()
  doxydata.set('VERSION', meson.project_version())


if find_program('dot', required : false).found()
  # In the real world this would set the variable
  # to YES. However we set it to NO so that the
  # list of generated files is always the same
  # so tests always pass.
  doxydata.set('HAVE_DOT', 'YES')
else
  doxydata.set('HAVE_DOT', 'NO')
endif

message ('doc generation disabled')
message('uncomment the subdir doc line in meson.build')
# subdir('doc')

