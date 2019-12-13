#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/pge/tiago_pge/src/pal_navigation_sm"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/pge/tiago_pge/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/pge/tiago_pge/install/lib/python2.7/dist-packages:/home/pge/tiago_pge/build/pal_navigation_sm/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/pge/tiago_pge/build/pal_navigation_sm" \
    "/usr/bin/python" \
    "/home/pge/tiago_pge/src/pal_navigation_sm/setup.py" \
    build --build-base "/home/pge/tiago_pge/build/pal_navigation_sm" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/pge/tiago_pge/install" --install-scripts="/home/pge/tiago_pge/install/bin"
