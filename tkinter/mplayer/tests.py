from pytest import approx

from . import mplay


class TestMplayer():

    def test1(self) -> None:
        assert (5 * 0.1) == approx(0.5)

    def test_init_values(self) -> None:
        assert mplay.init_vol == 70
        assert mplay.paused is False
        assert mplay.muted is False
