"""."""
from typing_extensions import Final

DEBUG: Final = True

if DEBUG is True:
    import cProfile
    import logging


def start_profiling() -> 'cProfile.Profile':
    import cProfile
    prof = cProfile.Profile()
    prof.enable()
    return prof


def set_up_logger() -> 'logging.Logger':
    import logging
    logger = logging.Logger("basic_log")
    return logger


def prof_to_stats(profile: cProfile.Profile) -> None:
    """."""
    import pstats
    import datetime

    now = datetime.datetime.now()
    stats = pstats.Stats(profile)
    stats.strip_dirs()
    stats.sort_stats('cumulative')
    stats.print_stats(15)
    filename = f'./logs/profile_{now.day}-{now.month}-{now.year}.prof'
    profile.dump_stats(filename)


def main() -> None:
    """."""
    if DEBUG is True:
        prof = start_profiling()

    import time
    start_time = time.perf_counter()
    import multiprocessing
    multiprocessing.freeze_support()
    print("starting...")

    from pathlib import Path
    from pycalc import main
    logger = set_up_logger()
    print(f"Imports done @ {time.perf_counter() - start_time:.2f} s")

    # icon_path = Path(R'.\coffeebean.ico')
    try:
        print(f"GUI started @ {time.perf_counter() - start_time:.2f} s")
        main()
    except (KeyboardInterrupt, SystemExit) as kexc:
        print('\nApp closed with ctrl-C')
        logger.info(repr(kexc))
    except Exception as exc:
        logger.exception(repr(exc))
        raise
    finally:
        print('DMLmung app closed')
        if DEBUG is True:
            prof.disable()
            prof_to_stats(prof)  # ; prof.print_stats(sort='cumtime')


if __name__ == "__main__":
    main()
