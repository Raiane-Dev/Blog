import { Image, Layout, Typography, Row, Button, Modal, Form, Input } from 'antd';
import walp from "../assets/images/walp.jpg"
import _Header from '../components/Header';
import _Footer from '../components/Footer';
import { useState } from 'react';
import { SeatProperty, SeatPattern } from "../@types/Seat";

const { Title, Paragraph } = Typography;

function Ticket(): any
{
    const [loading, setLoading] = useState(false);
    const [visible, setVisible] = useState(false);
    const [form] = Form.useForm();
    const [seat, setSeat]: any = useState<SeatProperty>(SeatPattern);

    const handleOk = async () => {}

    return (
        <>
            <_Header />

            <Layout className='root-content one'>
                <Row align='middle' justify='space-between'>
                    <Title level={4}>
                        Title
                    </Title>

                    <Button onClick={() => setVisible(true)}>
                        Buy now
                    </Button>
                </Row>

                <Row align='top' justify='space-between'>
                    <Image  src={walp} preview={false} />
                        
                    <Paragraph>
                        Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam euismod egestas faucibus. Maecenas lacinia enim vel risus pellentesque, ut ullamcorper odio vestibulum. Vestibulum quis gravida sapien. Curabitur sollicitudin pharetra risus, vitae placerat elit posuere eu. Cras nec velit felis...
                    </Paragraph>
                </Row>
            </Layout>

            <Modal
                title="Buy now"
                visible={visible}
                onOk={() => setVisible(false)}
                onCancel={() => setVisible(false)}
                footer={[
                    <Button key="back" onClick={() => setVisible(false)}>
                        Cancel
                    </Button>,
                    <Button key="submit" type="primary" loading={loading} onClick={handleOk}>
                        Buy
                    </Button>,
                ]}
            >
                <Form
                    name="basic"
                    labelCol={{ span: 8 }}
                    wrapperCol={{ span: 16 }}
                    initialValues={{ remember: true }}
                    onFinish={handleOk}
                    form={form}
                    autoComplete="off"
                >
                    <Row align='middle' justify-content='space-between' className="group">
                        <Form.Item
                            name="name"
                            rules={[{ required: true, message: 'Required auditorium!' }]}
                        >
                            <Input
                                placeholder="Row"
                                type="text"
                                onChange={(val: any) => setSeat({ ...seat, row: val.target.value })}
                            />
                        </Form.Item>


                        <Form.Item
                            name="seats_no"
                            rules={[{ required: true, message: 'Required seats!', type: 'number', min: 0 }]}
                        >
                            <Input
                                placeholder="Seats"
                                type="text"
                                onChange={(val: any) => setSeat({ ...seat, number: val.target.value })}
                            />
                        </Form.Item>
                    </Row>
                </Form>
            </Modal>

            <_Footer />
        </>
    );
};

export default Ticket;