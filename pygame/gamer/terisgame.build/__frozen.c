// This provides the frozen (compiled bytecode) files that are included if
// any.
#include <Python.h>

#include "nuitka/constants_blob.h"

// Blob from which modules are unstreamed.
#define stream_data constant_bin

// These modules should be loaded as bytecode. They may e.g. have to be loadable
// during "Py_Initialize" already, or for irrelevance, they are only included
// in this un-optimized form. These are not compiled by Nuitka, and therefore
// are not accelerated at all, merely bundled with the binary or module, so
// that CPython library can start out finding them.

struct frozen_desc {
    char const *name;
    ssize_t start;
    int size;
};

void copyFrozenModulesTo( struct _frozen *destination )
{
    struct frozen_desc frozen_modules[] = {
        { "_collections_abc", 6654388, 28939 },
        { "_compression", 6683327, 4086 },
        { "_weakrefset", 6687413, 7459 },
        { "abc", 6694872, 6448 },
        { "base64", 6701320, 17056 },
        { "bz2", 6718376, 11143 },
        { "codecs", 6729519, 33895 },
        { "collections", 6763414, -46607 },
        { "collections.abc", 6654388, 28939 },
        { "copyreg", 6810021, 4241 },
        { "dis", 6814262, 15167 },
        { "encodings", 6829429, -3944 },
        { "encodings.aliases", 6833373, 6293 },
        { "encodings.ascii", 6839666, 1881 },
        { "encodings.base64_codec", 6841547, 2420 },
        { "encodings.big5", 6843967, 1441 },
        { "encodings.big5hkscs", 6845408, 1451 },
        { "encodings.bz2_codec", 6846859, 3282 },
        { "encodings.charmap", 6850141, 2934 },
        { "encodings.cp037", 6853075, 2426 },
        { "encodings.cp1006", 6855501, 2502 },
        { "encodings.cp1026", 6858003, 2430 },
        { "encodings.cp1125", 6860433, 8123 },
        { "encodings.cp1140", 6868556, 2416 },
        { "encodings.cp1250", 6870972, 2453 },
        { "encodings.cp1251", 6873425, 2450 },
        { "encodings.cp1252", 6875875, 2453 },
        { "encodings.cp1253", 6878328, 2466 },
        { "encodings.cp1254", 6880794, 2455 },
        { "encodings.cp1255", 6883249, 2474 },
        { "encodings.cp1256", 6885723, 2452 },
        { "encodings.cp1257", 6888175, 2460 },
        { "encodings.cp1258", 6890635, 2458 },
        { "encodings.cp273", 6893093, 2412 },
        { "encodings.cp424", 6895505, 2456 },
        { "encodings.cp437", 6897961, 7840 },
        { "encodings.cp500", 6905801, 2426 },
        { "encodings.cp65001", 6908227, 1680 },
        { "encodings.cp720", 6909907, 2523 },
        { "encodings.cp737", 6912430, 8162 },
        { "encodings.cp775", 6920592, 7870 },
        { "encodings.cp850", 6928462, 7501 },
        { "encodings.cp852", 6935963, 7878 },
        { "encodings.cp855", 6943841, 8131 },
        { "encodings.cp856", 6951972, 2488 },
        { "encodings.cp857", 6954460, 7483 },
        { "encodings.cp858", 6961943, 7471 },
        { "encodings.cp860", 6969414, 7819 },
        { "encodings.cp861", 6977233, 7834 },
        { "encodings.cp862", 6985067, 8023 },
        { "encodings.cp863", 6993090, 7834 },
        { "encodings.cp864", 7000924, 7980 },
        { "encodings.cp865", 7008904, 7834 },
        { "encodings.cp866", 7016738, 8167 },
        { "encodings.cp869", 7024905, 7860 },
        { "encodings.cp874", 7032765, 2554 },
        { "encodings.cp875", 7035319, 2423 },
        { "encodings.cp932", 7037742, 1443 },
        { "encodings.cp949", 7039185, 1443 },
        { "encodings.cp950", 7040628, 1443 },
        { "encodings.euc_jis_2004", 7042071, 1457 },
        { "encodings.euc_jisx0213", 7043528, 1457 },
        { "encodings.euc_jp", 7044985, 1445 },
        { "encodings.euc_kr", 7046430, 1445 },
        { "encodings.gb18030", 7047875, 1447 },
        { "encodings.gb2312", 7049322, 1445 },
        { "encodings.gbk", 7050767, 1439 },
        { "encodings.hex_codec", 7052206, 2407 },
        { "encodings.hp_roman8", 7054613, 2627 },
        { "encodings.hz", 7057240, 1437 },
        { "encodings.idna", 7058677, 5721 },
        { "encodings.iso2022_jp", 7064398, 1458 },
        { "encodings.iso2022_jp_1", 7065856, 1462 },
        { "encodings.iso2022_jp_2", 7067318, 1462 },
        { "encodings.iso2022_jp_2004", 7068780, 1468 },
        { "encodings.iso2022_jp_3", 7070248, 1462 },
        { "encodings.iso2022_jp_ext", 7071710, 1466 },
        { "encodings.iso2022_kr", 7073176, 1458 },
        { "encodings.iso8859_1", 7074634, 2425 },
        { "encodings.iso8859_10", 7077059, 2430 },
        { "encodings.iso8859_11", 7079489, 2524 },
        { "encodings.iso8859_13", 7082013, 2433 },
        { "encodings.iso8859_14", 7084446, 2451 },
        { "encodings.iso8859_15", 7086897, 2430 },
        { "encodings.iso8859_16", 7089327, 2432 },
        { "encodings.iso8859_2", 7091759, 2425 },
        { "encodings.iso8859_3", 7094184, 2432 },
        { "encodings.iso8859_4", 7096616, 2425 },
        { "encodings.iso8859_5", 7099041, 2426 },
        { "encodings.iso8859_6", 7101467, 2470 },
        { "encodings.iso8859_7", 7103937, 2433 },
        { "encodings.iso8859_8", 7106370, 2464 },
        { "encodings.iso8859_9", 7108834, 2425 },
        { "encodings.johab", 7111259, 1443 },
        { "encodings.koi8_r", 7112702, 2477 },
        { "encodings.koi8_t", 7115179, 2388 },
        { "encodings.koi8_u", 7117567, 2463 },
        { "encodings.kz1048", 7120030, 2440 },
        { "encodings.latin_1", 7122470, 1893 },
        { "encodings.mac_arabic", 7124363, 7734 },
        { "encodings.mac_centeuro", 7132097, 2464 },
        { "encodings.mac_croatian", 7134561, 2472 },
        { "encodings.mac_cyrillic", 7137033, 2462 },
        { "encodings.mac_farsi", 7139495, 2406 },
        { "encodings.mac_greek", 7141901, 2446 },
        { "encodings.mac_iceland", 7144347, 2465 },
        { "encodings.mac_latin2", 7146812, 2606 },
        { "encodings.mac_roman", 7149418, 2463 },
        { "encodings.mac_romanian", 7151881, 2473 },
        { "encodings.mac_turkish", 7154354, 2466 },
        { "encodings.mbcs", 7156820, 1692 },
        { "encodings.oem", 7158512, 1505 },
        { "encodings.palmos", 7160017, 2453 },
        { "encodings.ptcp154", 7162470, 2547 },
        { "encodings.punycode", 7165017, 6414 },
        { "encodings.quopri_codec", 7171431, 2440 },
        { "encodings.raw_unicode_escape", 7173871, 1766 },
        { "encodings.rot_13", 7175637, 3026 },
        { "encodings.shift_jis", 7178663, 1451 },
        { "encodings.shift_jis_2004", 7180114, 1461 },
        { "encodings.shift_jisx0213", 7181575, 1461 },
        { "encodings.tis_620", 7183036, 2515 },
        { "encodings.undefined", 7185551, 2160 },
        { "encodings.unicode_escape", 7187711, 1746 },
        { "encodings.unicode_internal", 7189457, 1756 },
        { "encodings.utf_16", 7191213, 4830 },
        { "encodings.utf_16_be", 7196043, 1631 },
        { "encodings.utf_16_le", 7197674, 1631 },
        { "encodings.utf_32", 7199305, 4723 },
        { "encodings.utf_32_be", 7204028, 1524 },
        { "encodings.utf_32_le", 7205552, 1524 },
        { "encodings.utf_7", 7207076, 1552 },
        { "encodings.utf_8", 7208628, 1611 },
        { "encodings.utf_8_sig", 7210239, 4513 },
        { "encodings.uu_codec", 7214752, 3222 },
        { "encodings.zlib_codec", 7217974, 3120 },
        { "enum", 7221094, 23744 },
        { "functools", 7244838, 23811 },
        { "genericpath", 7268649, 3745 },
        { "heapq", 7272394, 14359 },
        { "importlib", 7286753, -3729 },
        { "importlib._bootstrap", 7290482, 29175 },
        { "importlib._bootstrap_external", 7319657, 41815 },
        { "importlib.machinery", 7361472, 969 },
        { "inspect", 7362441, 79632 },
        { "io", 7442073, 3406 },
        { "keyword", 7445479, 1806 },
        { "linecache", 7447285, 3786 },
        { "locale", 7451071, 34552 },
        { "ntpath", 7485623, 12916 },
        { "opcode", 7498539, 5340 },
        { "operator", 7503879, 13897 },
        { "os", 7517776, 29690 },
        { "quopri", 7547466, 5733 },
        { "re", 7553199, 13801 },
        { "reprlib", 7567000, 5347 },
        { "sre_compile", 7572347, 15200 },
        { "sre_constants", 7587547, 6288 },
        { "sre_parse", 7593835, 21354 },
        { "stat", 7615189, 3870 },
        { "stringprep", 7619059, 9994 },
        { "struct", 7629053, 331 },
        { "threading", 7629384, 37297 },
        { "token", 7666681, 3596 },
        { "tokenize", 7670277, 17727 },
        { "traceback", 7688004, 19475 },
        { "types", 7707479, 8971 },
        { "warnings", 7716450, 13763 },
        { NULL, 0, 0 }
    };

    struct frozen_desc *current = frozen_modules;

    for(;;)
    {
        destination->name = (char *)current->name;
        destination->code = (unsigned char *)&constant_bin[ current->start ];
        destination->size = current->size;

        if (destination->name == NULL) break;

        current += 1;
        destination += 1;
    };
}
