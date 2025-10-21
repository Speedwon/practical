from __future__ import annotations

from dataclasses import dataclass, field
from typing import List


@dataclass
class MobileDevice:
    """Опис мобільного пристрою."""

    brand: str
    model: str
    storage_gb: int
    price_usd: float
    battery_mah: int

    def __str__(self) -> str:
        return (
            f"{self.brand} {self.model}: {self.storage_gb} ГБ, "
            f"$ {self.price_usd:.2f}, акумулятор {self.battery_mah} мА·год"
        )


@dataclass
class MobileDeviceInventory:
    """Робота з масивом мобільних пристроїв."""

    devices: List[MobileDevice] = field(default_factory=list)

    @classmethod
    def with_sample_data(cls) -> "MobileDeviceInventory":
        """Створити інвентар з мінімум десяти пристроїв."""

        sample_devices = [
            MobileDevice("Apple", "iPhone 15", 256, 1199.0, 3349),
            MobileDevice("Samsung", "Galaxy S23", 128, 949.0, 3900),
            MobileDevice("Google", "Pixel 8", 128, 899.0, 4385),
            MobileDevice("OnePlus", "11", 256, 749.0, 5000),
            MobileDevice("Xiaomi", "13 Pro", 256, 999.0, 4820),
            MobileDevice("Sony", "Xperia 1 V", 256, 1399.0, 5000),
            MobileDevice("Nothing", "Phone (2)", 256, 649.0, 4700),
            MobileDevice("Motorola", "Edge 40", 256, 699.0, 4400),
            MobileDevice("Huawei", "P60 Pro", 256, 1099.0, 4815),
            MobileDevice("Asus", "ROG Phone 7", 512, 1299.0, 6000),
        ]
        return cls(sample_devices)

    def display(self) -> None:
        """Вивести всі пристрої на екран."""

        for index, device in enumerate(self.devices):
            print(f"[{index}] {device}")

    def update_device(self, index: int, **changes) -> MobileDevice:
        """Змінити значення полів вибраного пристрою."""

        try:
            device = self.devices[index]
        except IndexError as exc:  # noqa: PERF203
            raise IndexError(f"Неправильний індекс: {index}") from exc

        for field_name, new_value in changes.items():
            if not hasattr(device, field_name):
                raise AttributeError(f"Поле '{field_name}' не існує у MobileDevice")
            setattr(device, field_name, new_value)
        return device

    def filter_by_min_storage(self, min_storage: int) -> List[MobileDevice]:
        """Повернути пристрої з мінімальним обсягом пам'яті."""

        return [device for device in self.devices if device.storage_gb >= min_storage]

    def sort_by_price(self, descending: bool = False) -> None:
        """Відсортувати пристрої за ціною."""

        self.devices.sort(key=lambda device: device.price_usd, reverse=descending)


def main() -> None:
    inventory = MobileDeviceInventory.with_sample_data()

    print("Початковий список пристроїв:")
    inventory.display()

    print("\nМодифікація третього пристрою (індекс 2):")
    inventory.update_device(2, price_usd=829.0, storage_gb=256)
    inventory.display()

    print("\nПристрої з обсягом пам'яті не менше 256 ГБ:")
    for device in inventory.filter_by_min_storage(256):
        print(device)

    print("\nСортування за ціною за зростанням:")
    inventory.sort_by_price(descending=False)
    inventory.display()

    print("\nСортування за ціною за спаданням:")
    inventory.sort_by_price(descending=True)
    inventory.display()


if __name__ == "__main__":
    main()
